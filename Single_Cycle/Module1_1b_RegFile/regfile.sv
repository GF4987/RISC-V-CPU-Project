module regfile (
    input logic clk,
    input logic rst_n,

    //Reading to regfile
    input logic [4:0] rs1, //Address of source register 1
    input logic [4:0] rs2, //Address of source register 2
    output logic [31:0] read_data1, //Data read from source register 1
    output logic [31:0] read_data2, //Data read from source register

    //Writing to regfile
    input logic write_enable, //Enable signal for writing to the register file
    input logic [31:0] write_data,
    input logic [4:0] rs3

);

//32 bit registers, 32 registers in total, each address being 5-bits wide
reg [31:0] registers [0:31]; 

//Write regfile logic
always @(posedge clk) begin
    //Reset or else init to 0
    if (!rst_n) begin
        for (int i =0; i < 32; i++) begin
            registers[i] <= 32'b0; //Initializes all registers to 0 on reset
        end
    end

    //Write except on 0, its reserved for the 0 constant based on the RISC-V spec
    else if (write_enable && rs3 != 0) begin
        registers[rs3] <= write_data; //Writes the data to the register at the specific address
    end

end

//Read logic, asynchronous of clock
always_comb begin: readLogic
    read_data1 = registers[rs1]; //Reads the data from the register at the specific address for source register 1
    read_data2 = registers[rs2]; //Reads the data from the register at the specific address for source register 2
end

endmodule
