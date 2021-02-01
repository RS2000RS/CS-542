module booth_mul(input signed[7:0] a, input signed[7:0] b, output signed [15:0] c);
	wire signed [7:0] Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7;
	wire signed [7:0] m;
	wire signed [7:0] A0,A1,A2,A3,A4,A5,A6,A7;
	wire signed [7:0] q0; 
	wire outp;
	
	booth_step step_init(8'b00000000,a,1'b0,b,A1,Q1,q0[1]);
	booth_step step1(A1,Q1,q0[1],b,A2,Q2,q0[2]);
	booth_step step2(A2,Q2,q0[2],b,A3,Q3,q0[3]);
	booth_step step3(A3,Q3,q0[3],b,A4,Q4,q0[4]);
	booth_step step4(A4,Q4,q0[4],b,A5,Q5,q0[5]);
	booth_step step5(A5,Q5,q0[5],b,A6,Q6,q0[6]);
	booth_step step6(A6,Q6,q0[6],b,A7,Q7,q0[7]);
	booth_step step7(A7,Q7,q0[7],b,c[15:8],c[7:0],outp);
	
	 
endmodule



module booth_step(input wire signed [7:0]a, Q, input wire signed q0, input wire signed [7:0] m, output reg signed [7:0] f8, output reg signed [7:0] l8, output reg cq0);
	wire [7:0] subm,sub2m;
	subtractor subtr(a,m,subm);
	subtractor2 subtr2(a,m,sub2m);
	
		always @(*) begin	
		if(Q[0] == q0) begin
			 cq0 = Q[0];
			l8 = Q>>1;
			 l8[7] = a[0];
			 f8 = a>>1;
			if (a[7] == 1)
			f8[7] = 1;
		end

		else if(Q[0] == 1 && q0 ==0) begin
			 cq0 = Q[0];
				l8 = Q>>1;
			 l8[7] = sub2m[0];
			 f8 = sub2m>>1;
			if (sub2m[7] == 1)
			f8[7] = 1;
		end

		else begin
			 cq0 = Q[0];
				l8 = Q>>1;
			 l8[7] = subtr[0];
			 f8 = subtr>>1;
			if (subtr[7] == 1)
			f8[7] = 1;
		end

			
	
end	
endmodule 





 

