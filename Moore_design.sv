module FSM1(clk, reset, x, outp);
	input [0:0] clk;
	input [0:0] reset;
	input [0:0] x;
	output reg [0:0] outp;

	reg [1:0] state;
	reg [1:0] next_state;

	parameter A = 0;
	parameter B = 1;
	parameter C = 2;
	parameter D = 3;

	initial begin
		state = A;
	end

	always @(posedge clk, posedge reset)
		begin
			if(reset)
				state <= A;
			else
				state <= next_state;
		end

always @(state, x)
	begin
		case (state)
			A:
					if(x==0)
						next_state=B;
					else
						next_state=A;
			B:
					if(x==0)
						next_state=B;
					else
						next_state=C;
			C:
					if(x==0)
						next_state=D;
					else
						next_state=C;
			D:
					if(x==0)
						next_state=D;
					else
						next_state=A;
		endcase
	end

	always @(state, x)
		begin
			case (state)
				A: if(x)
					outp = 1'b1;
				else
					outp = 1'b1;
				B: if(x)
					outp = 1'b0;
				else
					outp = 1'b0;
				C: if(x)
					outp = 1'b0;
				else
					outp = 1'b0;
				D: if(x)
					outp = 1'b0;
				else
					outp = 1'b0;
				default: outp = 1'b0;
			endcase
		end
endmodule