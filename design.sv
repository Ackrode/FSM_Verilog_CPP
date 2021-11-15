// Output logic
	always @(state, x)
		begin
			case (state)
				A: if(x)
					outp = 1'b0
					outp = 1'b1
					outp = 1'b1
					outp = 1'b0
				B: if(x)
					outp = 1'b0
					outp = 1'b0
				C: if(x)
					outp = 1'b0
					outp = 1'b1
				D: if(x)
					outp = 1'b0
					outp = 1'b0
				E: if(x)
					outp = 1'b0
					outp = 1'b1
				F: if(x)
					outp = 1'b0
					outp = 1'b0
			endcase
		end
endmodule