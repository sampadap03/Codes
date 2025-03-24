#include<simplecpp>
main_program
{

cout<<"Here we are going to draw a graph of runs scored.\n";
cout<<"Let the data be as follows:\n";
cout<<"Over \t\t Runs scored\n";
cout<<"____________________________________";
cout<<"\n\n";
cout<<"46\t\t3\n";
cout<<"47\t\t6\n";
cout<<"48\t\t2\n";
cout<<"49\t\t8\n";
cout<<"50\t\t12";      

initCanvas("CRICKER RUNS GRAPH",1920,1080);

Line l1(260,0,260,1080);
Line l2(0,850,1920,850);

Rectangle r1(490,775,140,150);
Rectangle r2(790,700,140,300);
Rectangle r3(1090,800,140,100);
Rectangle r4(1390,650,140,400);
Rectangle r5(1690,550,140,600);

Text t1(960,980,"NUMBER OF OVERS");
Text t2(110,400,"N");
Text t3(110,415,"U");
Text t4(110,430,"M");
Text t5(110,445,"B");
Text t6(110,460,"E");
Text t7(110,475,"R");
Text t8(110,505,"O");
Text t9(110,520,"F");
Text t10(110,550,"R");
Text t11(110,565,"U");
Text t12(110,580,"N");
Text t13(110,595,"S");

Text t14(960,100,"GRAPH OF RUNS IN 5 OVERS");
Text t15(490,860,"46");
Text t16(790,860,"47");
Text t17(1090,860,"48");
Text t18(1390,860,"49");
Text t19(1690,860,"50");

r1.setFill(true);
r2.setFill(true);
r3.setFill(true);



r4.setFill(true);
r5.setFill(true);

l1.setFill(true);
l2.setFill(true);

r1.setColor(COLOR(251,80,51));
r2.setColor(COLOR(74,155,228));



r3.setColor(COLOR(251,80,51));
r4.setColor(COLOR(74,155,228));
r5.setColor(COLOR(251,80,51));

l1.setColor(COLOR(18,2,114));
l2.setColor(COLOR(18,2,114));



Line l3(0,5,1920,5);
Line l4(5,0,5,1080);
Line l5(0,1075,1920,1075);
Line l6(1915,0,1915,1080);

wait(20);

cout<<"\n";
}
