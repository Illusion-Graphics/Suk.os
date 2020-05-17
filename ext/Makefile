LIBFDT_dir = libfdt
LIBFDT_archive = $(BUILD_DIR)/libfdt.a
LIBFDT_lib = $(BUILD_DIR)/$(LIBFDT_LIB)
LIBFDT_include = $(addprefix $(LIBFDT_dir)/,$(LIBFDT_INCLUDES))
LIBFDT_version = $(addprefix $(LIBFDT_dir)/,$(LIBFDT_VERSION))


include $(LIBFDT_dir)/Makefile.libfdt

all: $(LIBFDT_OBJS)

$(LIBFDT_OBJS): $(addprefix $(LIBFDT_dir)/,$(LIBFDT_OBJS))

$(LIBFDT_lib): $(addprefix $(LIBFDT_dir)/,$(LIBFDT_OBJS)) $(LIBFDT_version)
	@$(VECHO) LD $@
	$(CC) $(LDFLAGS) $(SHAREDLIB_LDFLAGS)$(LIBFDT_soname) -o $(LIBFDT_lib) \
		$(addprefix $(LIBFDT_dir)/,$(LIBFDT_OBJS))
	ln -sf $(LIBFDT_LIB) $(LIBFDT_dir)/$(LIBFDT_soname)