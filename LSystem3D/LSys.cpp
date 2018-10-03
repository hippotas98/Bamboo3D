#include "LSys.h"
using namespace std;
namespace zero
{
void LSys::generate()
{
    vector<char> newSentence;
    for (int i = 0; i < sentence.size(); ++i)
    {
        // cout << sentence[i] << endl;
        if (rule.find(sentence[i]) != rule.end())
        {
            string s = rule[sentence[i]];
            // cout << "string: " << s << endl;
            for (int iter = 0; iter < s.length(); ++iter)
            {
                newSentence.push_back(s[iter]);
            }
        }
        else
        {
            newSentence.push_back(sentence[i]);
        }
    }
    // cout << "------------\n";
    sentence = newSentence;
}
void LSys::printSentence()
{
    for (int i = 0; i < sentence.size(); ++i)
    {
        cout << sentence[i];
    }
    cout << endl;
}

void LSys::turle3D()
{
    GLdouble angle = 25;
    stack<float> s;
    GLdouble h = 2;
    Color32 fruitC(100, 139, 0, 255);
    Color32 leafC(100,139,0,255);
    Color32 treeC(139, 40, 35, 255);
    GLdouble radius = 0.4;
    float base = 0.2f;
    float top = 0.2f;
    for (int i = 0; i < sentence.size(); ++i)
    {
        char c = sentence[i];
        switch (c)
        {
            case 'F':
            {
                drawCyline(base, base, h, 0, 0, 0, treeC);
                // base = base*0.7 >= 0.05f ? base*0.99 : 0.05f;
                base *= 0.9;
                glTranslatef(0, 0, h);
                break;
            }
            case 'X':
            {
                drawLeaf(leafC);
                break;
            }
            case '+':
            {
                // rotate right by y axis 
                glRotatef(angle, 0, 1, 0);
                break;
            }
            case '-':
            {
                 // rotate left by y axis 
                glRotatef(-angle, 0, 1, 0);
                break;
            }
            case '*':
            {
                // rotate right by x axis 
                 glRotatef(angle, 1, 0, 0);
                 break;
            }
            case '/':
            {
                // rotate left by x axis 
                 glRotatef(-angle, 1, 0, 0);
                 break;
            }
            case '^':
            {
                // rotate right by z axis 
                 glRotatef(angle, 0, 0, 1);
                 break;
            }
            case '@':
            {
                 // rotate left by z axis 
                 glRotatef(-angle, 0, 0, 1);
                 break;
            }
            case '[':
            {
                glPushMatrix();
                s.push(base);
                break;
            }
            case ']':
            {
                base = s.top();
                s.pop();
                glPopMatrix();
                break;
            }
        }
    }
}
void LSys::drawCyline(float base, float top, float h, float anglX, float anglY,
                      float anglZ, const Color32 &c)
{
    glColor3f(c.r/255.0f, c.g/255.0f, c.b/255.0f);

    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, base, top, h, 10, 10);
}

void LSys::drawSphere(float radius, const Color32 &c)
{
    glColor3f(c.r/255.0f, c.g/255.0f, c.b/255.0f);
    glutSolidSphere(radius, 20, 20);
}
    void LSys::drawLeaf(const Color32 &c)
    {
        
            glBegin(GL_TRIANGLES);
            glNormal3f(-0.1, 0, 0.25);
            glVertex3f(0, 0, 0);
            glVertex3f(0.25, 0.25, 0.1);
            glVertex3f(0, 0.5, 0);
            
            glNormal3f(0.1, 0, 0.25);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0.5, 0);
            glVertex3f(-0.25, 0.25, 0.1);
            glEnd();
        
    }
} // namespace zero
