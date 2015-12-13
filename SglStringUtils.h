/*
Licensed to the Square Gears Logic (SGL) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The SGL licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#ifndef SGLSTRINGUTILS_H
#define SGLSTRINGUTILS_H

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

namespace SglUtils {

using namespace std;

class SglStringUtils
{
public:
    // int to string convertion - implementation of non-standard ita function.
    static inline string itoa(int i)
    {
        char a[50];
        sprintf(a,"%d",i);
        return string(a);
    }

    // checks if string is a valid integer number
    static inline bool isNumber(const string& s)
    {
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    // replaces all instances of from with to in str
    static inline string ReplaceAll(string str, const string& from, const string& to) {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }

    // splits line into vector by delimiter
    static inline vector<string> splitString(string &what, string &delim, const bool isStrong=false)
    {
        vector<string> flds;
        string work = what;
        int i = 0;
        while (i < work.length()) {
            int pos = work.find(delim, i);
            if (pos == string::npos)
                break;
            if (pos == i && !isStrong)
            {
                i += delim.length();
                continue;
            }
            flds.push_back(what.substr(i, pos));
            i = pos + delim.length();
        }
        return flds;
    }

    // trim from start
    static inline string &ltrim(string &s) {
            s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
            return s;
    }

    // trim from end
    static inline string &rtrim(string &s) {
            s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
            return s;
    }

    // trim from both ends
    static inline string &trim(string &s) {
            return ltrim(rtrim(s));
    }

    static inline string toLowCase(string &s)
    {
        string result = s;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

private:
    SglStringUtils();
};

};
#endif // SGLSTRINGUTILS_H
