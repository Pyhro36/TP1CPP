#makefile de test de Collection
#la viriable EXE correspond au nom du test a effectuer (et au 
#pour tester la fontion Retirer de la classe : EXE = TRetiter
#pour tester la fonction Ajuster de la classe : EXE = TAjuster

EXE = TAjuster
COMP = g++
RM = rm
EDL = g++
ECHO = @echo
INTF = Collection.h 
REAL = $(INTF:.h=.cpp) $(EXE).cpp
OBJ = $(REAL:.cpp=.o)
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = #-Wall -FMAP
EDLFALGS =
LIBS =
LIBPATH =
INPATH =
CLEAN = clean
SOS = backup

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

$(EXE).o : $(EXE).cpp Collection.h
Collection.o : Collection.cpp Collection.h

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGGS) $(INPATH) -c $<

$(CLEAN) :
	$(ECHO) "Nettoyage des fichiers crees !"
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) #core

#$(SOS)
