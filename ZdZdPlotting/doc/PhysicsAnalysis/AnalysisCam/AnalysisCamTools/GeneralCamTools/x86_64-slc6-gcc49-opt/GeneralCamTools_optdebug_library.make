#-- start of make_header -----------------

#====================================
#  Document GeneralCamTools_optdebug_library
#
#   Generated Sat Nov 19 20:07:23 2016  by diboye
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_GeneralCamTools_optdebug_library_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_GeneralCamTools_optdebug_library_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_GeneralCamTools_optdebug_library

GeneralCamTools_tag = $(tag)

#cmt_local_tagfile_GeneralCamTools_optdebug_library = $(GeneralCamTools_tag)_GeneralCamTools_optdebug_library.make
cmt_local_tagfile_GeneralCamTools_optdebug_library = $(bin)$(GeneralCamTools_tag)_GeneralCamTools_optdebug_library.make

else

tags      = $(tag),$(CMTEXTRATAGS)

GeneralCamTools_tag = $(tag)

#cmt_local_tagfile_GeneralCamTools_optdebug_library = $(GeneralCamTools_tag).make
cmt_local_tagfile_GeneralCamTools_optdebug_library = $(bin)$(GeneralCamTools_tag).make

endif

include $(cmt_local_tagfile_GeneralCamTools_optdebug_library)
#-include $(cmt_local_tagfile_GeneralCamTools_optdebug_library)

ifdef cmt_GeneralCamTools_optdebug_library_has_target_tag

cmt_final_setup_GeneralCamTools_optdebug_library = $(bin)setup_GeneralCamTools_optdebug_library.make
cmt_dependencies_in_GeneralCamTools_optdebug_library = $(bin)dependencies_GeneralCamTools_optdebug_library.in
#cmt_final_setup_GeneralCamTools_optdebug_library = $(bin)GeneralCamTools_GeneralCamTools_optdebug_librarysetup.make
cmt_local_GeneralCamTools_optdebug_library_makefile = $(bin)GeneralCamTools_optdebug_library.make

else

cmt_final_setup_GeneralCamTools_optdebug_library = $(bin)setup.make
cmt_dependencies_in_GeneralCamTools_optdebug_library = $(bin)dependencies.in
#cmt_final_setup_GeneralCamTools_optdebug_library = $(bin)GeneralCamToolssetup.make
cmt_local_GeneralCamTools_optdebug_library_makefile = $(bin)GeneralCamTools_optdebug_library.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)GeneralCamToolssetup.make

#GeneralCamTools_optdebug_library :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'GeneralCamTools_optdebug_library'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = GeneralCamTools_optdebug_library/
#GeneralCamTools_optdebug_library::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of optdebug_library_header ------
# create  a  two  part  executable.   One  a
# stripped  binary  which will occupy less space in RAM and in a dis-
# tribution and the second a debugging information file which is only
# needed  if  debugging abilities are required
# See GNU binutils OBJCOPY(1)
# http://sourceware.org/binutils/docs-2.17/binutils/objcopy.html#objcopy

depend=$(bin)$(library_prefix)GeneralCamTools.$(shlibsuffix)
target=$(depend)$(debuginfosuffix)

GeneralCamTools_optdebug_library :: $(target) ;

$(target) : $(depend)
	$(echo) stripping dbg symbols into separate file $@
	$(link_silent) objcopy --only-keep-debug $< $@
	$(link_silent) objcopy --strip-debug $<
	$(link_silent) cd $(@D) && objcopy --add-gnu-debuglink=$(@F) $(<F)
	$(link_silent) touch -c $@

GeneralCamTools_optdebug_libraryclean ::
	$(cleanup_silent) /bin/rm -f $(target)

#-----------------------------------------------------------------
#
#  New section for automatic installation
#
#-----------------------------------------------------------------

install_dir = ${CMTINSTALLAREA}/$(tag)/lib
GeneralCamTools_optdebug_libraryinstallname = $(library_prefix)GeneralCamTools$(library_suffix).$(shlibsuffix)$(debuginfosuffix)

GeneralCamTools_optdebug_library :: GeneralCamTools_optdebug_libraryinstall ;

install :: GeneralCamTools_optdebug_libraryinstall ;

GeneralCamTools_optdebug_libraryinstall :: $(install_dir)/$(GeneralCamTools_optdebug_libraryinstallname)
ifdef CMTINSTALLAREA
	$(echo) "$(GeneralCamTools_optdebug_libraryinstallname) installation done"
endif

$(install_dir)/$(GeneralCamTools_optdebug_libraryinstallname) :: $(bin)$(GeneralCamTools_optdebug_libraryinstallname)
ifdef CMTINSTALLAREA
	$(install_silent) $(cmt_install_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(GeneralCamTools_optdebug_libraryinstallname)" \
	    -out "$(install_dir)" \
	    -cmd "$(cmt_installarea_command)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

##GeneralCamTools_optdebug_libraryclean :: GeneralCamTools_optdebug_libraryuninstall

uninstall :: GeneralCamTools_optdebug_libraryuninstall ;

GeneralCamTools_optdebug_libraryuninstall ::
ifdef CMTINSTALLAREA
	$(cleanup_silent) $(cmt_uninstall_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(GeneralCamTools_optdebug_libraryinstallname)" \
	    -out "$(install_dir)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

#-- start of optdebug_library_header ------
#-- start of cleanup_header --------------

clean :: GeneralCamTools_optdebug_libraryclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(GeneralCamTools_optdebug_library.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

GeneralCamTools_optdebug_libraryclean ::
#-- end of cleanup_header ---------------
