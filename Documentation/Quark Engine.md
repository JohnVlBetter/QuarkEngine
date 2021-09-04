[TOC]

# Quark Engine

## Overview

***

### Description

Quark Engine基于OpenGL图形库，运行于Windows和Linux操作系统，主要用于游戏开发及动画渲染。  

***

### Architecture

Quark Engine的整体架构图如下图所示。  

![Architecture](.\Images\引擎架构图.png)

***

#### Overall Description

#### Hardware

#### Operating System

#### Third Part

##### Assimp

##### Glad

##### GLFW

##### ImGui

##### Premake

##### yaml

##### ImGuizmo

##### entt

##### glm

##### spdlog

##### stb_image

#### Platform Independent Layer

#### Core System

#### Engine Assets

#### And so on will be added later

## Development Environment and Build

### Development Environment

#### C++17

#### Visual Studio 2017

#### Python

#### Lua

#### GLSL

### Build

Double left-click on GenerateProjects.bat

## Engine Documentation

## Render Engine Document

## Agile Process

### 2021

#### Sprint1 Goal

* ~~GitHub repo and Project build~~
* ~~Basic Engine~~
* ~~2D Renderer(Quad)~~
* ~~Basica Events~~
* ~~Logger~~
* ~~Camera~~

#### Sprint2 Goal

+ ~~Basica Editor~~
+ ~~Scene File IO~~
+ ~~Gizmo~~
+ ~~Texture~~
+ ~~ECS~~

#### Sprint3 Goal

+ ~~Drag/Drop Assets~~
+ ~~Input system~~
+ ~~Premake build Solution~~
+ ~~Basic Shader system~~
+ ~~Properties/Scene/Hierarchy/Assets panel~~

#### Sprint4 Goal

+ Assimp import model(.obj/.fbx)
+ Skeleton animation
+ Skybox
+ Basic Material
+ Basic 3D Renderer

#### Sprint5 Goal

## Road Map

### Release 2021

Editor、Animation、Basic Render、IO、Assets、Build、Physic.

## Research

### Assimp

***

#### Interpolate Keys

调研：对于Assimp中的操作，-120°与240°、-180°与180°、360°与0°等等没有区别，最后计算得出的四元数相等，Assimp会对于这种情况做逆时针的负值处理，即旋转-120°、-180°与0°。进而使得动画旋转产生错误。

解决方案：在Assimp的FBXConverter中拓展InterpolateKeys函数，首先在GenerateSimpleNodeAnim函数获取旋转信息数组，根据数组内每个KeyValue进行检查，对于大于等于180°的KeyValue进行拆分记录。将记录传入InterpolateKeys函数，在函数中进行Position及Rotation的线性插值，及对Rotation的角度进行拆分计算。并将结果通过valOut返回，进而赋值到每个CurveNodeAnim的Keys中，从而完成插值。

***

#### AI_COFIG_IMPORT_FBX_PRESERVE_PIVOTS

***

#### Binding Pose Missing nodes

调研：Assimp中设有AI_CONFIG_IMPORT_FBX_REMOVE_EMPTY_BONES的设置，于代码中也会将对Mesh Vertex无影响的bone做删除处理，而有些模型文件会缺失Bind Pose的联系，即Bone与Curve Node的联系，对应的tag将会为NULL，从而使得模型导入后pose设置错误，模型动作抽象。

解决方案：在FBXDocument中记录null节点，进而联系到对应的model，对于model的名字进行控制台报错输出。

***

### PhysX

### Premake

### Mono



