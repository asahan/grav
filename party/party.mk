##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=party
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Administrator\Documents\CodeLite\grav"
ProjectPath            := "C:\Users\Administrator\Documents\CodeLite\grav\party"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=11/08/14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:\MinGW-4.8.1\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.8.1\bin\g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="party.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.8.1\bin\windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glut32 $(LibrarySwitch)opengl32 $(LibrarySwitch)glu32 
ArLibs                 :=  "libglut32.a" "libopengl32.a" "libglu32.a" 
LibPath                :=$(LibraryPathSwitch)C:/MinGW-4.8.1/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\MinGW-4.8.1\bin\ar.exe rcu
CXX      := C:\MinGW-4.8.1\bin\g++.exe 
CC       := C:\MinGW-4.8.1\bin\gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.8.1\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/instGame.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionSphere.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionPlane.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionCube.cpp$(ObjectSuffix) $(IntermediateDirectory)/CollisionObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/Clock.cpp$(ObjectSuffix) $(IntermediateDirectory)/Displayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/EventHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Matrix3h.cpp$(ObjectSuffix) $(IntermediateDirectory)/Matrix4h.cpp$(ObjectSuffix) $(IntermediateDirectory)/Quath.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vector3h.cpp$(ObjectSuffix) $(IntermediateDirectory)/Vector4h.cpp$(ObjectSuffix) $(IntermediateDirectory)/Line3h.cpp$(ObjectSuffix) $(IntermediateDirectory)/CPlane.cpp$(ObjectSuffix) $(IntermediateDirectory)/CShape.cpp$(ObjectSuffix) $(IntermediateDirectory)/CSphere.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/CLine.cpp$(ObjectSuffix) $(IntermediateDirectory)/CCube.cpp$(ObjectSuffix) $(IntermediateDirectory)/AABB.cpp$(ObjectSuffix) $(IntermediateDirectory)/BoundingSphere.cpp$(ObjectSuffix) $(IntermediateDirectory)/OBB.cpp$(ObjectSuffix) $(IntermediateDirectory)/Rigidbody.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/instGame.cpp$(ObjectSuffix): instGame.cpp $(IntermediateDirectory)/instGame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/instGame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/instGame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/instGame.cpp$(DependSuffix): instGame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/instGame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/instGame.cpp$(DependSuffix) -MM "instGame.cpp"

$(IntermediateDirectory)/instGame.cpp$(PreprocessSuffix): instGame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/instGame.cpp$(PreprocessSuffix) "instGame.cpp"

$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix): CollisionHandler.cpp $(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CollisionHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix): CollisionHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix) -MM "CollisionHandler.cpp"

$(IntermediateDirectory)/CollisionHandler.cpp$(PreprocessSuffix): CollisionHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionHandler.cpp$(PreprocessSuffix) "CollisionHandler.cpp"

$(IntermediateDirectory)/CollisionSphere.cpp$(ObjectSuffix): CollisionSphere.cpp $(IntermediateDirectory)/CollisionSphere.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CollisionSphere.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionSphere.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionSphere.cpp$(DependSuffix): CollisionSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionSphere.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionSphere.cpp$(DependSuffix) -MM "CollisionSphere.cpp"

$(IntermediateDirectory)/CollisionSphere.cpp$(PreprocessSuffix): CollisionSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionSphere.cpp$(PreprocessSuffix) "CollisionSphere.cpp"

$(IntermediateDirectory)/CollisionPlane.cpp$(ObjectSuffix): CollisionPlane.cpp $(IntermediateDirectory)/CollisionPlane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CollisionPlane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionPlane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionPlane.cpp$(DependSuffix): CollisionPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionPlane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionPlane.cpp$(DependSuffix) -MM "CollisionPlane.cpp"

$(IntermediateDirectory)/CollisionPlane.cpp$(PreprocessSuffix): CollisionPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionPlane.cpp$(PreprocessSuffix) "CollisionPlane.cpp"

$(IntermediateDirectory)/CollisionCube.cpp$(ObjectSuffix): CollisionCube.cpp $(IntermediateDirectory)/CollisionCube.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CollisionCube.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionCube.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionCube.cpp$(DependSuffix): CollisionCube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionCube.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionCube.cpp$(DependSuffix) -MM "CollisionCube.cpp"

$(IntermediateDirectory)/CollisionCube.cpp$(PreprocessSuffix): CollisionCube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionCube.cpp$(PreprocessSuffix) "CollisionCube.cpp"

$(IntermediateDirectory)/CollisionObject.cpp$(ObjectSuffix): CollisionObject.cpp $(IntermediateDirectory)/CollisionObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CollisionObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CollisionObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CollisionObject.cpp$(DependSuffix): CollisionObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CollisionObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CollisionObject.cpp$(DependSuffix) -MM "CollisionObject.cpp"

$(IntermediateDirectory)/CollisionObject.cpp$(PreprocessSuffix): CollisionObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CollisionObject.cpp$(PreprocessSuffix) "CollisionObject.cpp"

$(IntermediateDirectory)/Clock.cpp$(ObjectSuffix): Clock.cpp $(IntermediateDirectory)/Clock.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Clock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Clock.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Clock.cpp$(DependSuffix): Clock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Clock.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Clock.cpp$(DependSuffix) -MM "Clock.cpp"

$(IntermediateDirectory)/Clock.cpp$(PreprocessSuffix): Clock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Clock.cpp$(PreprocessSuffix) "Clock.cpp"

$(IntermediateDirectory)/Displayer.cpp$(ObjectSuffix): Displayer.cpp $(IntermediateDirectory)/Displayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Displayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Displayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Displayer.cpp$(DependSuffix): Displayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Displayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Displayer.cpp$(DependSuffix) -MM "Displayer.cpp"

$(IntermediateDirectory)/Displayer.cpp$(PreprocessSuffix): Displayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Displayer.cpp$(PreprocessSuffix) "Displayer.cpp"

$(IntermediateDirectory)/EventHandler.cpp$(ObjectSuffix): EventHandler.cpp $(IntermediateDirectory)/EventHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/EventHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EventHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EventHandler.cpp$(DependSuffix): EventHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EventHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EventHandler.cpp$(DependSuffix) -MM "EventHandler.cpp"

$(IntermediateDirectory)/EventHandler.cpp$(PreprocessSuffix): EventHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EventHandler.cpp$(PreprocessSuffix) "EventHandler.cpp"

$(IntermediateDirectory)/Game.cpp$(ObjectSuffix): Game.cpp $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game.cpp$(DependSuffix) -MM "Game.cpp"

$(IntermediateDirectory)/Game.cpp$(PreprocessSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix) "Game.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Matrix3h.cpp$(ObjectSuffix): Matrix3h.cpp $(IntermediateDirectory)/Matrix3h.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Matrix3h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrix3h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Matrix3h.cpp$(DependSuffix): Matrix3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Matrix3h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Matrix3h.cpp$(DependSuffix) -MM "Matrix3h.cpp"

$(IntermediateDirectory)/Matrix3h.cpp$(PreprocessSuffix): Matrix3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Matrix3h.cpp$(PreprocessSuffix) "Matrix3h.cpp"

$(IntermediateDirectory)/Matrix4h.cpp$(ObjectSuffix): Matrix4h.cpp $(IntermediateDirectory)/Matrix4h.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Matrix4h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrix4h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Matrix4h.cpp$(DependSuffix): Matrix4h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Matrix4h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Matrix4h.cpp$(DependSuffix) -MM "Matrix4h.cpp"

$(IntermediateDirectory)/Matrix4h.cpp$(PreprocessSuffix): Matrix4h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Matrix4h.cpp$(PreprocessSuffix) "Matrix4h.cpp"

$(IntermediateDirectory)/Quath.cpp$(ObjectSuffix): Quath.cpp $(IntermediateDirectory)/Quath.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Quath.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Quath.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Quath.cpp$(DependSuffix): Quath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Quath.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Quath.cpp$(DependSuffix) -MM "Quath.cpp"

$(IntermediateDirectory)/Quath.cpp$(PreprocessSuffix): Quath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Quath.cpp$(PreprocessSuffix) "Quath.cpp"

$(IntermediateDirectory)/Vector3h.cpp$(ObjectSuffix): Vector3h.cpp $(IntermediateDirectory)/Vector3h.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Vector3h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vector3h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vector3h.cpp$(DependSuffix): Vector3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vector3h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vector3h.cpp$(DependSuffix) -MM "Vector3h.cpp"

$(IntermediateDirectory)/Vector3h.cpp$(PreprocessSuffix): Vector3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vector3h.cpp$(PreprocessSuffix) "Vector3h.cpp"

$(IntermediateDirectory)/Vector4h.cpp$(ObjectSuffix): Vector4h.cpp $(IntermediateDirectory)/Vector4h.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Vector4h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Vector4h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Vector4h.cpp$(DependSuffix): Vector4h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Vector4h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Vector4h.cpp$(DependSuffix) -MM "Vector4h.cpp"

$(IntermediateDirectory)/Vector4h.cpp$(PreprocessSuffix): Vector4h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Vector4h.cpp$(PreprocessSuffix) "Vector4h.cpp"

$(IntermediateDirectory)/Line3h.cpp$(ObjectSuffix): Line3h.cpp $(IntermediateDirectory)/Line3h.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Line3h.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Line3h.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Line3h.cpp$(DependSuffix): Line3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Line3h.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Line3h.cpp$(DependSuffix) -MM "Line3h.cpp"

$(IntermediateDirectory)/Line3h.cpp$(PreprocessSuffix): Line3h.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Line3h.cpp$(PreprocessSuffix) "Line3h.cpp"

$(IntermediateDirectory)/CPlane.cpp$(ObjectSuffix): CPlane.cpp $(IntermediateDirectory)/CPlane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CPlane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CPlane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CPlane.cpp$(DependSuffix): CPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CPlane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CPlane.cpp$(DependSuffix) -MM "CPlane.cpp"

$(IntermediateDirectory)/CPlane.cpp$(PreprocessSuffix): CPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CPlane.cpp$(PreprocessSuffix) "CPlane.cpp"

$(IntermediateDirectory)/CShape.cpp$(ObjectSuffix): CShape.cpp $(IntermediateDirectory)/CShape.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CShape.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CShape.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CShape.cpp$(DependSuffix): CShape.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CShape.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CShape.cpp$(DependSuffix) -MM "CShape.cpp"

$(IntermediateDirectory)/CShape.cpp$(PreprocessSuffix): CShape.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CShape.cpp$(PreprocessSuffix) "CShape.cpp"

$(IntermediateDirectory)/CSphere.cpp$(ObjectSuffix): CSphere.cpp $(IntermediateDirectory)/CSphere.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CSphere.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CSphere.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CSphere.cpp$(DependSuffix): CSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CSphere.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CSphere.cpp$(DependSuffix) -MM "CSphere.cpp"

$(IntermediateDirectory)/CSphere.cpp$(PreprocessSuffix): CSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CSphere.cpp$(PreprocessSuffix) "CSphere.cpp"

$(IntermediateDirectory)/CLine.cpp$(ObjectSuffix): CLine.cpp $(IntermediateDirectory)/CLine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CLine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CLine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CLine.cpp$(DependSuffix): CLine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CLine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CLine.cpp$(DependSuffix) -MM "CLine.cpp"

$(IntermediateDirectory)/CLine.cpp$(PreprocessSuffix): CLine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CLine.cpp$(PreprocessSuffix) "CLine.cpp"

$(IntermediateDirectory)/CCube.cpp$(ObjectSuffix): CCube.cpp $(IntermediateDirectory)/CCube.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/CCube.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CCube.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CCube.cpp$(DependSuffix): CCube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CCube.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CCube.cpp$(DependSuffix) -MM "CCube.cpp"

$(IntermediateDirectory)/CCube.cpp$(PreprocessSuffix): CCube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CCube.cpp$(PreprocessSuffix) "CCube.cpp"

$(IntermediateDirectory)/AABB.cpp$(ObjectSuffix): AABB.cpp $(IntermediateDirectory)/AABB.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/AABB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AABB.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AABB.cpp$(DependSuffix): AABB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AABB.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AABB.cpp$(DependSuffix) -MM "AABB.cpp"

$(IntermediateDirectory)/AABB.cpp$(PreprocessSuffix): AABB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AABB.cpp$(PreprocessSuffix) "AABB.cpp"

$(IntermediateDirectory)/BoundingSphere.cpp$(ObjectSuffix): BoundingSphere.cpp $(IntermediateDirectory)/BoundingSphere.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/BoundingSphere.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BoundingSphere.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BoundingSphere.cpp$(DependSuffix): BoundingSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BoundingSphere.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BoundingSphere.cpp$(DependSuffix) -MM "BoundingSphere.cpp"

$(IntermediateDirectory)/BoundingSphere.cpp$(PreprocessSuffix): BoundingSphere.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BoundingSphere.cpp$(PreprocessSuffix) "BoundingSphere.cpp"

$(IntermediateDirectory)/OBB.cpp$(ObjectSuffix): OBB.cpp $(IntermediateDirectory)/OBB.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/OBB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OBB.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OBB.cpp$(DependSuffix): OBB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OBB.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OBB.cpp$(DependSuffix) -MM "OBB.cpp"

$(IntermediateDirectory)/OBB.cpp$(PreprocessSuffix): OBB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OBB.cpp$(PreprocessSuffix) "OBB.cpp"

$(IntermediateDirectory)/Rigidbody.cpp$(ObjectSuffix): Rigidbody.cpp $(IntermediateDirectory)/Rigidbody.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Administrator/Documents/CodeLite/grav/party/Rigidbody.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Rigidbody.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Rigidbody.cpp$(DependSuffix): Rigidbody.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Rigidbody.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Rigidbody.cpp$(DependSuffix) -MM "Rigidbody.cpp"

$(IntermediateDirectory)/Rigidbody.cpp$(PreprocessSuffix): Rigidbody.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Rigidbody.cpp$(PreprocessSuffix) "Rigidbody.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/instGame.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/instGame.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/instGame.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CollisionHandler.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CollisionHandler.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CollisionHandler.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CollisionSphere.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CollisionSphere.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CollisionSphere.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CollisionPlane.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CollisionPlane.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CollisionPlane.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CollisionCube.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CollisionCube.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CollisionCube.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CollisionObject.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CollisionObject.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CollisionObject.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Clock.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Clock.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Clock.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Displayer.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Displayer.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Displayer.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/EventHandler.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/EventHandler.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/EventHandler.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Matrix3h.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Matrix3h.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Matrix3h.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Matrix4h.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Matrix4h.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Matrix4h.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Quath.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Quath.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Quath.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Vector3h.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Vector3h.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Vector3h.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Vector4h.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Vector4h.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Vector4h.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Line3h.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Line3h.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Line3h.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CPlane.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CPlane.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CPlane.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CShape.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CShape.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CShape.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CSphere.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CSphere.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CSphere.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CLine.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CLine.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CLine.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CCube.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CCube.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CCube.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/AABB.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/AABB.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/AABB.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/BoundingSphere.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/BoundingSphere.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/BoundingSphere.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OBB.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OBB.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OBB.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Rigidbody.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Rigidbody.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Rigidbody.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/party"


