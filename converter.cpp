//
// Created by yhtyyar on 10.03.2020.
//
#include <string>
#include <map>
#include <iostream>

using std::map;
using std::string;

namespace
{
     static map<long long , string> vocabulary_map = {
            {0, "nol"},
            {1, "bir"},  {2, "iki"},   {3, "uch"},
            {4, "dort"}, {5, "bash"},  {6, "alty"},
            {7, "yedi"}, {8, "sekiz"}, {9, "dokuz"},

            {10, "on"},      {20, "yigrimi"}, {30, "otuz"},
            {40, "kyrk"},    {50, "elli"},    {60, "altmysh"},
            {70, "yetmish"}, {80, "segsen"},  {90, "dogsan"},

            {100, "yuz"}, {1000, "mun"}, {1000000, "million"},
            {1000000000, "milliard"},
            {1000000000000, "trillion"}
    };

    string  val(const long long n) {

        return  vocabulary_map[n];
    }

    static const long long grouping[] = {
            (long long) 1e12,
            (long long) 1e9,
            (long long) 1e6,
             1000,
             100,
    };

    void convert(long long number, string &answer) {

       for (int i = 0; i < 5; ++i) {
           if (number >= grouping[i]) {
               convert(number / grouping[i], answer);
               answer += " ";
               answer += val(grouping[i]);
               number %= (grouping[i]);
           }
       }
       if (number >= 10) {
           answer += " ";
           answer += val(number / 10 * 10);
           number %= 10;
       }
       if (number > 0) {
           answer += " ";
           answer += val(number);
       }
    }
}
//PRE : number < 10^15 && number > -10^15
//POST : R -> number in turkmen language
string convert_to_turkmen(long long number) {
    if (llabs(number) >= 1e15) {
        std::cerr << "Too big number to convert" << std::endl;
        return "Error";
    }
    string answer = "";
    if (number == 0)
        return val(0);
    if (number < 0)
        answer = "minus";
    convert(llabs(number), answer);
    if (number > 0)
        answer.erase(answer.begin());  // deleting first unneeded space
    return answer;
}
