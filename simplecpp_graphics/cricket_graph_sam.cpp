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

initCanvas("CRICKER RUNS GRAPH",1366,768);

Line l1(166,0,166,768);
Line l2(0,600,1366,600);

Rectangle r1(306,540,160,120);
Rectangle r2(526,480,160,240);
Rectangle r3(746,560,160,80);
Rectangle r4(966,440,160,320);
Rectangle r5(1186,360,160,480);

Text t1(683,684,"NUMBER OF OVERS");
Text t2(83,280,"N");
Text t3(83,295,"U");
Text t4(83,310,"M");
Text t5(83,325,"B");
Text t6(83,340,"E");
Text t7(83,355,"R");
Text t8(83,385,"O");
Text t9(83,400,"F");
Text t10(83,430,"R");
Text t11(83,445,"U");
Text t12(83,460,"N");
Text t13(83,475,"S");

Text t14(683,60,"GRAPH OF RUNS IN 5 OVERS");
Text t15(306,610,"46");
Text t16(526,610,"47");
Text t17(746,610,"48");
Text t18(966,610,"49");
Text t19(1186,610,"50");

Text t20(160,40,"14");
Text t21(160,120,"12");
Text t22(160,200,"10");
Text t23(160,280,"8");
Text t24(160,360,"6");
Text t25(160,440,"4");
Text t26(160,520,"2");

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

wait(20);

cout<<"\n";
}
