#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Qiime2FilterPlugin.h"

void Qiime2FilterPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Qiime2FilterPlugin::run() {
   
}

void Qiime2FilterPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";	
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";	
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime "+parameters["op1"]+" ";
   command += parameters["op2"]+" ";
   if (parameters["op2"] == "filter-features")
      command += "--i-table "+std::string(PluginManager::prefix())+"/"+parameters["inputfile"]+" ";
   else
      command += "--i-data "+std::string(PluginManager::prefix())+"/"+parameters["inputfile"]+" ";
   command += "--m-metadata-file "+std::string(PluginManager::prefix())+"/"+parameters["metadata"]+" ";
   if (parameters["op2"] == "filter-features")
      command += "--o-filtered-table "+file+";";
   else
	   command += "--o-filtered-data "+file+";";
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<Qiime2FilterPlugin> Qiime2FilterPluginProxy = PluginProxy<Qiime2FilterPlugin>("Qiime2Filter", PluginManager::getInstance());
