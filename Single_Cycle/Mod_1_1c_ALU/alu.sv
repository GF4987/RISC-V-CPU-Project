module alu (
    input logic [2:0] alu_control, //Signal that determines what operation of the ALU is asserted
    input logic [31:0] operand1, //First operand for the ALU operation
    input logic [31:0] operand2, //Second operand for the ALU operation

    output logic [31:0] alu_result, //Result of the ALU operation
    output logic zero //Signal that is asserted if the result of the ALU operation is zero
);


always_comb begin
    case (alu_control)
        3'b000: alu_result = operand1 + operand2; //Addition
        default: alu_result = 32'b0; //Default case, result is zero
    endcase
end


assign zero = alu_result == 32'b0; //Zero if ALU output is also 0

endmodule
