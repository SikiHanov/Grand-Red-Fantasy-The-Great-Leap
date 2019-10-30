#pragma once

enum buildClass {};
enum buildType {};

class BaseBuild 
{
public:
	int id;
	buildClass emBuildClass;
	buildType emBuildType;
private:
};

class CivBuild : public BaseBuild
{

};

class MilBuild : public BaseBuild
{

};

class NatBuild : public BaseBuild
{


};