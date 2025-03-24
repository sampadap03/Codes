//Purpose: To make a program of runs versus overs of cricket match

//Date: 05/09/2017

//Gr. No.: 1710536

//Roll No.: C 34

//Name : Sampada Petkar




#include<simplecpp>


main_program // main program starts here

{

int a,b,c,d,e,v,w,x,y,z;



cout<<"Enter the runs scored in five overs seperately:";

cout<<"You must enter the runs less than 14";


cin>>a>>b>>c>>d>>e;



cout<<"Here we are going to draw a graph of runs scored.\n";
 // outputs showing values
cout<<"Let the data be as follows:\n";
cout<<"Over \t\t Runs scored\n";
cout<<"____________________________________";
cout<<"\n\n";
cout<<"46\t\t3\n";
cout<<"47\t\t6\n";
cout<<"48\t\t2\n";
cout<<"49\t\t8\n";
cout<<"50\t\t12";   

v=40*a;
w=40*b;
x=40*c;
y=40*d;
z=40*e;   

initCanvas("CRICKER RUNS GRAPH",1024,768);  // canvas starts here
                 
Line l1(124,0,124,768);  // axes 
Line l2(0,600,1024,600);

Rectangle r1(234,600-v,120,2*v); // rectangular bars of bar graph 
Rectangle r2(404,600-w,120,2*w);
Rectangle r3(574,600-x,120,2*x);
Rectangle r4(744,600-y,120,2*y);
Rectangle r5(914,600-z,120,2*z);

Text t1(512,684,"NUMBER OF OVERS");  // header of x axis
Text t2(62,200,"N");  // header of y axis starts here
Text t3(62,215,"U");
Text t4(62,230,"M");
Text t5(62,245,"B");
Text t6(62,260,"E");
Text t7(62,275,"R");
Text t8(62,305,"O");
Text t9(62,320,"F");
Text t10(62,350,"R");
Text t11(62,365,"U");
Text t12(62,385,"N");
Text t13(62,400,"S");

Text t14(512,40,"GRAPH OF RUNS IN 5 OVERS");  // header of program printed by this
Text t15(234,615,"46");  // this prints the overs
Text t16(404,615,"47");
Text t17(574,615,"48");
Text t18(744,615,"49");
Text t19(914,615,"50");

Text t20(100,40,"14");
Text t21(100,120,"12"); 
Text t22(100,200,"10");
Text t23(100,280,"8");
Text t24(100,360,"6");
Text t25(100,440,"4");
Text t26(100,520,"2");

r1.setFill(true); // allows to colour the text
r2.setFill(true);
r3.setFill(true);



r4.setFill(true);
r5.setFill(true);

l1.setFill(true);
l2.setFill(true);

r1.setColor(COLOR(251,80,51));  // it states the colour
r2.setColor(COLOR(74,155,228));



r3.setColor(COLOR(251,80,51));
r4.setColor(COLOR(74,155,228));
r5.setColor(COLOR(251,80,51));

l1.setColor(COLOR(18,2,114));
l2.setColor(COLOR(18,2,114));

wait(20);

cout<<"\n";
}

