//
//  FileUtils.h
//  ShaderLiveMaker
//
//  Created by Martin Hermant on 29/08/2016.
//
//

#ifndef FileUtils_h
#define FileUtils_h


#ifdef __APPLE__
#ifndef st_mtime
#define st_mtime st_mtimespec.tv_sec
#endif
#endif
#include <sys/stat.h>

#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

inline time_t get_last_modified(const string & file) {
  struct tm *clock(nullptr);
  struct stat attr;

  stat(file.c_str(), &attr);
  clock = gmtime(&(attr.st_mtime));
  return mktime(clock);

  
}

inline string parseFileToString(const string &  file){

  ifstream t(file);
  return string((istreambuf_iterator<char>(t)),
                  istreambuf_iterator<char>());
}

inline string joinPath(const string & first,const string & second){
  return first+"/"+second;
}



#endif /* FileUtils_h */
