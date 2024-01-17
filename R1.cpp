#include<bits/stdc++.h>
using namespace std;

struct cubie
{
    int colour;                      // 1-green, 2-blue, 3-red, 4-orange, 5-white, 6-yellow
    int piece;                       // Side piece - 0 , Center piece - 1
};

class cube
{
    cubie green[3][3];
    cubie blue[3][3];
    cubie red[3][3];
    cubie orange[3][3];
    cubie white[3][3];
    cubie yellow[3][3];
    cube()
    {
        //input the cube
    }
    void f_rc_face(cubie side[3][3])               //This is the operation when one side is rotated clockwise for the face
    {                                              // rotation clocwise             
        cubie temp=side[0][0];
        side[0][0]=side[2][0];
        side[2][0]=side[2][2];
        side[2][2]=side[0][2];
        side[0][2]=temp;
    }

    void f_rcc_face(cubie side[3][3])              //This is the operation when one side is rotated counter-clockwise for the face
    {                                              // rotation counter-clocwise             
        cubie temp=side[0][0];
        side[0][0]=side[0][2];
        side[0][2]=side[2][2];
        side[2][0]=temp;
        side[2][2]=side[2][0];
    }
    void f_rc_others(cubie side1[3][3], cubie side2[3][3], cubie side3[3][3], cubie side4[3][3])
    {
        cubie t1=side1[0][2];
        cubie t2=side1[1][2];
        cubie t3=side1[2][2];                                                   //This is the operation when one side is rotated clockwise for the face

        side1[0][2]=side4[0][0];                                                //Rotation Clockwise
        side1[1][2]=side4[0][1];
        side1[2][2]=side4[0][2];

        side4[0][0]=side3[2][0];
        side4[0][1]=side3[1][0];
        side4[0][2]=side3[0][0];

        side3[0][0]=side2[2][0];
        side3[1][0]=side2[2][1];
        side3[2][0]=side2[2][2];

        side2[2][0]=t3;
        side2[2][1]=t2;
        side2[2][2]=t1;   
    }
    void f_rcc_others(cubie side1[3][3], cubie side2[3][3], cubie side3[3][3], cubie side4[3][3])
    {
        cubie t1=side1[0][2];
        cubie t2=side1[1][2];
        cubie t3=side1[2][2];                                                   //This is the operation when one side is rotated counter-clockwise for the face

        side1[0][2]=side2[2][2];                                                //Rotation Clockwise
        side1[1][2]=side2[2][1];
        side1[2][2]=side2[2][0];

        side2[2][0]=side3[0][0];
        side2[2][1]=side3[1][0];
        side2[2][2]=side3[2][0];

        side3[2][0]=side4[0][0];
        side3[1][0]=side4[0][1];
        side3[0][0]=side4[0][2];
        
        side4[0][0]=t1;
        side4[0][1]=t2;
        side4[0][2]=t3; 
    }
    //All operations are done with green as front, white as top and yellow as down
    //Side 1 is always on the left of the face and side 2 its top   
    void f_c()                                                  //Front clockwise                             
    {
        f_rc_face(green);
        f_rc_others(orange,white,red,yellow);

    }
    void f_cc()                                                 //Front counter-clockwise  
    {
        f_rcc_face(green);
        f_rcc_others(orange,white,red,yellow);
    }

    void u_c()                                                  //Up clockwise  
    {
        f_rc_face(white);
        f_rc_others(orange,blue,red,green);

    }
    void u_cc()                                                 //Up counter-clockwise
    {
        f_rcc_face(white);
        f_rcc_others(orange,blue,red,green);
    }

    void b_c()
    {
        f_rc_face(blue);
        f_rc_others(red,white,orange,yellow);

    }
    void b_cc()
    {
        f_rcc_face(blue);
        f_rcc_others(red,white,orange,yellow);
    }

    void d_c()
    {
        f_rc_face(yellow);
        f_rc_others(orange,green,red,blue);

    }
    void d_cc()
    {
        f_rcc_face(yellow);
        f_rcc_others(orange,green,red,blue);

    }

    void r_c()
    {
        f_rc_face(red);
        f_rc_others(green,white,blue,yellow);
    }
    void r_cc()
    {
        f_rcc_face(red);
        f_rcc_others(green,white,blue,yellow);
    }

    void l_c()
    {
        f_rc_face(orange);
        f_rc_others(blue,white,green,yellow);
    }
    void l_cc()
    {
        f_rcc_face(orange);
        f_rcc_others(blue,white,green,yellow);
    }
    //All rotations end here


};