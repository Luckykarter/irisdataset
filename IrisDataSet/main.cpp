//
//  main.cpp
//  IrisDataSet
//
//  Created by Egor Wexler on 08/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include "getIrisClass.h"

using namespace std;
namespace fs = std::__fs::filesystem;


int main(int argc, const char * argv[]) {
    fs::path basePath = ".";
    for_each(fs::directory_iterator(basePath), fs::directory_iterator(),
             [](fs::directory_entry p){
        string fileName = p.path().string();
        if(fileName.find(".data") == string::npos) return;
        
//        cout << fileName << endl;
        fstream file;
        string line;
        float sepal_len, sepal_wid, petal_len, petal_wid;
        vector<float> t_sepal_len, t_sepal_wid, t_petal_len, t_petal_wid, t_class;
        vector<vector<float>> dataSet;
        string irisName;
        
        file.open(fileName);
        
        
        while(getline(file, line)) {
            replace(line.begin(), line.end(), ',', ' ');
            // we need a space-separated line
            
            istringstream iss(line);
            
            iss >> sepal_len >> sepal_wid >> petal_len >> petal_wid >> irisName;
            t_sepal_len.push_back(sepal_len);
            t_sepal_wid.push_back(sepal_wid);
            t_petal_len.push_back(petal_len);
            t_petal_wid.push_back(petal_wid);
            t_class.push_back(getIrisClass(irisName));
            dataSet.push_back(t_sepal_len);
            dataSet.push_back(t_sepal_wid);
            dataSet.push_back(t_petal_len);
            dataSet.push_back(t_sepal_wid);
            dataSet.push_back(t_class);
            
            
            
            cout << line << endl;
                
            
        }
        
        file.close();
        
    });
    
}
