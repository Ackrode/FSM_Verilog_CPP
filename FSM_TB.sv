`timescale 1ns/1ns
module FSM_TB;
reg [0:0] clk;
reg [0:0] reset;
reg [0:0] x;
wire [0:0] y;
FSM DUT(clk,reset,x,y);
initial begin 
$dumpfile("design.vcd");
$dumpvars(0, FSM_TB);
// addd stimulus
$display("*********************************************");
clk = 1'b0; reset = 1'b1; x = 1'b0; #2
reset = 1'b0; x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, y = %b", clk, reset, x, y);
x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, y = %b", clk, reset, x, y);
x = 1'b1; #2
$display("clk = %b, reset = %b, x = %b, y = %b", clk, reset, x, y);
x = 1'b1; #2
$display("clk = %b, reset = %b, x = %b, y = %b", clk, reset, x, y);
x = 1'b0; #2
$display("clk = %b, reset = %b, x = %b, y = %b", clk, reset, x, y);
$finish;
 end
 always #1 clk = ~clk;
endmodule
