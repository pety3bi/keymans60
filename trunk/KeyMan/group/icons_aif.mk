# Copyright (c) 2005, Nokia. All rights reserved

ifeq (WINS,$(findstring WINS, $(PLATFORM)))
ZDIR=$(EPOCROOT)\epoc32\release\$(PLATFORM)\$(CFG)\Z
else
ZDIR=$(EPOCROOT)\epoc32\data\z
endif

TARGETDIR=$(ZDIR)\SYSTEM\APPS\KEYMAN
ICONTARGETFILENAME=$(TARGETDIR)\KEYMAN_AIF.MIF

do_nothing :
	@rem do_nothing

MAKMAKE : do_nothing

BLD : do_nothing

CLEAN : do_nothing

LIB : do_nothing

CLEANLIB : do_nothing

RESOURCE :
	mifconv $(ICONTARGETFILENAME) \
		/c8,8 ..\icon\KeyMan.svg

FREEZE : do_nothing

SAVESPACE : do_nothing

RELEASABLES :
	@echo $(ICONTARGETFILENAME)

FINAL : do_nothing
