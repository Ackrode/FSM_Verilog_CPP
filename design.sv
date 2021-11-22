module FSM(clk, reset, x, y);
	input [0:0] clk;
	input [0:0] reset;
	input [0:0] x;
	output reg [0:0] y;

	reg [2:0] state;
	reg [2:0] next_state;

	parameter A = 0;
	parameter B = 1;
	parameter C = 2;
	parameter D = 3;
	parameter E = 4;
	parameter F = 5;

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
						next_state=E;
					else
						next_state=D;
			B:
					if(x==0)
						next_state=F;
					else
						next_state=D;
			C:
					if(x==0)
						next_state=E;
					else
						next_state=B;
			D:
					if(x==0)
						next_state=F;
					else
						next_state=B;
			E:
					if(x==0)
						next_state=C;
					else
						next_state=F;
			F:
					if(x==0)
						next_state=B;
					else
						next_state=C;
		endcase
	end

	always @(state, x)
		begin
			case (state)
				A: if(x)
					y = 1'b1;
				else
					y = 1'b0;
				B: if(x)
					y = 1'b0;
				else
					y = 1'b0;
				C: if(x)
					y = 1'b1;
				else
					y = 1'b0;
				D: if(x)
					y = 1'b0;
				else
					y = 1'b0;
				E: if(x)
					y = 1'b1;
				else
					y = 1'b0;
				F: if(x)
					y = 1'b0;
				else
					y = 1'b0;
				default: y = 1'b0;
			endcase
		end
endmodule