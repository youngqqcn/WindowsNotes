CPP=cl.exe
CPP_FLAG="/c"
LINK32=link.exe
LINK_LIB=user32.lib

ALL: CLEAN 
	@echo Building....
	$(CPP)  window.c $(CPP_FLAG)
	$(LINK32)  window.obj $(LINK_LIB) 

CLEAN:
	@echo deleting....
	del *.exe
	del *.obj