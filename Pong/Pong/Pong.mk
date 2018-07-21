##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Pong
ConfigurationName      :=Debug
WorkspacePath          :=/home/paulo/estudos/games/Pong
ProjectPath            :=/home/paulo/estudos/games/Pong/Pong
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Paulo Ricardo
Date                   :=21/07/18
CodeLitePath           :=/home/paulo/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Pong.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/SFML 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/HUD.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) $(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bastao.cpp$(ObjectSuffix) $(IntermediateDirectory)/Input.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	cp DS-DIGIT.TTF Debug
	@echo Done

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM Engine.cpp

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) Engine.cpp

$(IntermediateDirectory)/HUD.cpp$(ObjectSuffix): HUD.cpp $(IntermediateDirectory)/HUD.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/HUD.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HUD.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HUD.cpp$(DependSuffix): HUD.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HUD.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HUD.cpp$(DependSuffix) -MM HUD.cpp

$(IntermediateDirectory)/HUD.cpp$(PreprocessSuffix): HUD.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HUD.cpp$(PreprocessSuffix) HUD.cpp

$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix): Bola.cpp $(IntermediateDirectory)/Bola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/Bola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bola.cpp$(DependSuffix): Bola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bola.cpp$(DependSuffix) -MM Bola.cpp

$(IntermediateDirectory)/Bola.cpp$(PreprocessSuffix): Bola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bola.cpp$(PreprocessSuffix) Bola.cpp

$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix): Draw.cpp $(IntermediateDirectory)/Draw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/Draw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Draw.cpp$(DependSuffix): Draw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Draw.cpp$(DependSuffix) -MM Draw.cpp

$(IntermediateDirectory)/Draw.cpp$(PreprocessSuffix): Draw.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Draw.cpp$(PreprocessSuffix) Draw.cpp

$(IntermediateDirectory)/Bastao.cpp$(ObjectSuffix): Bastao.cpp $(IntermediateDirectory)/Bastao.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/Bastao.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bastao.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bastao.cpp$(DependSuffix): Bastao.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bastao.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bastao.cpp$(DependSuffix) -MM Bastao.cpp

$(IntermediateDirectory)/Bastao.cpp$(PreprocessSuffix): Bastao.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bastao.cpp$(PreprocessSuffix) Bastao.cpp

$(IntermediateDirectory)/Input.cpp$(ObjectSuffix): Input.cpp $(IntermediateDirectory)/Input.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/paulo/estudos/games/Pong/Pong/Input.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Input.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Input.cpp$(DependSuffix): Input.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Input.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Input.cpp$(DependSuffix) -MM Input.cpp

$(IntermediateDirectory)/Input.cpp$(PreprocessSuffix): Input.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Input.cpp$(PreprocessSuffix) Input.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


