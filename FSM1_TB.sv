`timescale 1ns/1ns
module FSM1_TB;
reg [0:0] clk;
reg [0:0] reset;
reg [0:0] x;
wire [0:0] outp;
FSM1 DUT(clk,reset,x,outp);
initial begin 
$dumpfile("design.vcd");
$dumpvars(0, FSM1_TB);
// addd stimulus
`timescale 1ns/1ns
module FSM1_TB;
reg [0:0] clk;
reg [0:0] reset;
reg [0:0] x;
wire [0:0] outp;
FSM1 DUT(clk,reset,x,outp);
initial begin 
$dumpfile("design.vcd");
$dumpvars(0, FSM1_TB);
// addd stimulus
$display(*********************************************);
clk = 1'b0; reset = 1'b1; x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, outp = %b", clk, reset, x, outp);
reset = 1'b0;
x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, outp = %b", clk, reset, x, outp);
x = 1'b1; #2
$display("clk = %b, reset = %b, x = %b, outp = %b", clk, reset, x, outp);
x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, outp = %b", clk, reset, x, outp);
x = 1'b1; #2
$display("clk = %b, reset = %b, x = %b, outp = %b", clk, reset, x, outp);
$finish;
 end
 always #1 clk = ~clk;
endmodule
