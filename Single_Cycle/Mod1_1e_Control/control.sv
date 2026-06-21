module control (
    input logic [6:0] opcode,
    input logic [2:0] func3,
    input logic [6:0] func7,
    input logic alu_zero,

    output logic [2:0] alu_control,
    output logic [1:0] imm_source,
    output logic mem_write,
    output logic reg_write
);

//Main Decoder
logic [1:0] alu_op;

always_comb begin
    case (opcode)
        //LW instruction
        7'b000011: begin
            reg_write = 1'b1;
            imm_source = 2'b00;
            mem_write = 1'b0;
            alu_op = 2'b00;
        end
        //Every other instruction
        default: begin
            reg_write = 1'b0;
            imm_source = 2'b00;
            mem_write = 1'b0;
            alu_op = 2'b00;
        end
    endcase
end


//ALU Decoder
always_comb begin
    case(alu_op)
        //LW, SW instructions
        2'b00: alu_control = 3'b000;
        //Every other instruction
        default: alu_control = 3'b111;
    endcase
end


endmodule
