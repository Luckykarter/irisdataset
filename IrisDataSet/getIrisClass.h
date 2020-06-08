//
//  getIrisClass.h
//  IrisDataSet
//
//  Created by Egor Wexler on 08/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#ifndef getIrisClass_h
#define getIrisClass_h
#include <string>
using namespace std;
int getIrisClass(const string& iris) {
    enum Iris {setosa = 1, versicolor, virginica, unknown };
    
    if(iris.find("setosa") != string::npos) return setosa;
    else if (iris.find("versicolor") != string::npos) return versicolor;
    else if (iris.find("virginica") != string::npos) return virginica;
    else return unknown;
    
}

#endif /* getIrisClass_h */
