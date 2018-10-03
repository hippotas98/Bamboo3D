#pragma
#include <vector>
#include <map>
#include <iostream>
#include "Point.h"
#include "Color.h"
#include <unistd.h>
#include <stack>
namespace zero
{
class LSys
{
    char axiom;
    std::map<char, std::string > rule;
    std::vector<char> sentence;

  public:
    LSys(char c)
    {
        /*2d
        axiom = 'X';
        std::vector<char> v;
        // v.push_back('A');
        // v.push_back('B');
        // std::vector<char> v1;
        // v1.push_back('A');
        rule['X'] = std::string("F[+FX][-FX]FX");
        rule['F'] = std::string("FF");
        // rule['B'] = v1;
        sentence.push_back('X');
        */
       //3d
       /*
        axiom = 'X';
        rule['X'] = std::string("F[+FX][-FX]F[*FX][/FX]FX");
        rule['F'] = std::string("FF");
        // rule['B'] = v1;
        sentence.push_back('X');
        */
       axiom = 'X';
       rule['A'] = std::string("F[++A]X[--A]^^^A");
       sentence.push_back('F');
       sentence.push_back('F');
       sentence.push_back('F');
       sentence.push_back('F');
       sentence.push_back('F');
       sentence.push_back('A');


    }
    void generate();
    void printSentence();
    void turle3D();
    void drawCyline(float, float, float, float , float , float, const Color32 &);
    void drawSphere(float, const Color32&);
};
} // namespace zero