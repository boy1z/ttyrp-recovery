# Copyright 2009 The Android Open Source Project

LOCAL_PATH := $(call my-dir)

updater_src_files := \
	install.c \
	updater.c

#
# Build the device-side library
#
include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(updater_src_files)

LOCAL_STATIC_LIBRARIES := $(TARGET_RECOVERY_UPDATER_LIBS) $(TARGET_RECOVERY_UPDATER_EXTRA_LIBS)
LOCAL_STATIC_LIBRARIES += libapplypatch libedify libmtdutils libminzip libz
LOCAL_STATIC_LIBRARIES += libmincrypt libbz
LOCAL_STATIC_LIBRARIES += libcutils libstdc++ libc
LOCAL_C_INCLUDES += $(LOCAL_PATH)/..

# Each library in TARGET_RECOVERY_UPDATER_LIBS should have a function
# named "Register_<libname>()".  Here we emit a little C function that
# gets #included by updater.c.  It calls all those registration
# functions.

# Devices can also add libraries to TARGET_RECOVERY_UPDATER_EXTRA_LIBS.
# These libs are also linked in with updater, but we don't try to call
# any sort of registration function for these.  Use this variable for
# any subsidiary static libraries required for your registered
# extension libs.

inc := $(call intermediates-dir-for,PACKAGING,updater_extensions)/register.inc

# During the first pass of reading the makefiles, we dump the list of
# extension libs to a temp file, then copy that to the ".list" file if
# it is different than the existing .list (if any).  The register.inc
# file then uses the .list as a prerequisite, so it is only rebuilt
# (and updater.o recompiled) when the list of extension libs changes.

junk := $(shell mkdir -p $(dir $(inc));\
	        echo $(TARGET_RECOVERY_UPDATER_LIBS) > $(inc).temp;\
	        diff -q $(inc).temp $(inc).list || cp -f $(inc).temp $(inc).list)

$(inc) : libs := $(TARGET_RECOVERY_UPDATER_LIBS)
$(inc) : $(inc).list
	$(hide) mkdir -p $(dir $@)
	$(hide) echo "" > $@
	$(hide) $(foreach lib,$(libs),echo "extern void Register_$(lib)(void);" >> $@)
	$(hide) echo "void RegisterDeviceExtensions() {" >> $@
	$(hide) $(foreach lib,$(libs),echo "  Register_$(lib)();" >> $@)
	$(hide) echo "}" >> $@

$(call intermediates-dir-for,EXECUTABLES,updater)/updater.o : $(inc)
LOCAL_C_INCLUDES += $(dir $(inc))

LOCAL_MODULE := updater

LOCAL_FORCE_STATIC_EXECUTABLE := true

include $(BUILD_EXECUTABLE)