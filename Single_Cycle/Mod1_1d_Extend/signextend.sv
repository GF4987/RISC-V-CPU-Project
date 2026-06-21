module signextend (
    input logic [24:0] raw_input,
    input logic [1:0] imm_source,

    output logic [31:0] immediate
);

    logic [11:0] gathered_imm; // The intermediate value before sign extension

    always_comb begin
        case(imm_source)
            2'b00: gathered_imm = raw_input[24:13];
            default: gathered_imm = 12'b0;
        endcase
    end

    assign immediate = {{20{gathered_imm[11]}}, gathered_imm};

endmodule
