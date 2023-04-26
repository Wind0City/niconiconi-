```
LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY shifter IS
	PORT (
			rst_n		 : IN BIT;
			data_in   : IN STD_LOGIC_VECTOR(7 DOWNTO 0);  
			n         : IN STD_LOGIC_VECTOR(2 DOWNTO 0);  
			dir       : IN STD_LOGIC;                     
			kind      : IN STD_LOGIC_VECTOR(1 DOWNTO 0);  
			clock     : IN BIT;                        
			data_out  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0) 
  );
END shifter;
	     
ARCHITECTURE behav of shifter IS
 -- VARIABLE	data_in_s : STD_LOGIC_VECTOR(7 DOWNTO 0);
	BEGIN
		
	  PROCESS (data_in, n, dir, kind,clock,rst_n)  
			VARIABLE	x,y : STD_LOGIC_VECTOR(7 DOWNTO 0);
			VARIABLE	ctrl0,ctrl1,ctrl2 : STD_LOGIC_VECTOR (3 DOWNTO 0);
			BEGIN
				IF(rst_n = '0')THEN
					data_out <= data_in;
					
			   ELSIF(clock'EVENT AND clock = '1')THEN
	
			  ctrl0 := n(0) & dir & kind(1) & kind(0);
			  ctrl1 := n(1) & dir & kind(1) & kind(0);
			  ctrl2 := n(2) & dir & kind(1) & kind(0);
						
			  CASE ctrl0 IS
				 WHEN "0000" | "0001" | "0010" | "0100" | "0101" | "0110"  =>  x := data_in;  
				 WHEN "1000" => x := data_in(6 DOWNTO 0) & data_in(0);                        
				 WHEN "1001" => x := data_in(6 DOWNTO 0) & '0';                               
				 WHEN "1010" => x := data_in(6 DOWNTO 0) & data_in(7);                        
				 WHEN "1100" => x := data_in(7) & data_in(7 DOWNTO 1);                         
				 WHEN "1101" => x := '0' & data_in(7 DOWNTO 1);                               
				 WHEN "1110" => x := data_in(0) & data_in(7 DOWNTO 1);                        
				 WHEN others => null;
			  END CASE;
			  
			  CASE ctrl1 IS
				 WHEN "0000" | "0001" | "0010" | "0100" | "0101" | "0110"  =>  y := x;       
				 WHEN "1000" => y := x(5 DOWNTO 0) & x(0) & x(0);                             
				 WHEN "1001" => y := x(5 DOWNTO 0) & "00";                                   
				 WHEN "1010" => y := x(5 DOWNTO 0) & x(7 DOWNTO 6);                         
				 WHEN "1100" => y := x(7) & x(7) & x(7 DOWNTO 2);                             
				 WHEN "1101" => y := "00" & x(7 DOWNTO 2);                                   
				 WHEN "1110" => y := x(1 DOWNTO 0) & x(7 DOWNTO 2);                          
				 WHEN others => null;
			  END CASE;
			  
			  CASE ctrl2 IS
				 WHEN "0000" | "0001" | "0010" | "0100" | "0101" | "0110"  => data_out <= y;  
				 WHEN "1000" => data_out <= y(3 DOWNTO 0) & y(0) & y(0) & y(0) & y(0);       
				 WHEN "1001" => data_out <= y(3 DOWNTO 0) & "0000";                           
				 WHEN "1010" | "1110" => data_out <= y(3 DOWNTO 0) & y(7 DOWNTO 4);          
				 WHEN "1100" => data_out <= y(7) & y(7) & y(7) & y(7) & y(7 DOWNTO 4);      
				 WHEN "1101" => data_out <= "0000" & y(7 DOWNTO 4);                      
				 WHEN others => null;
			  END CASE;       
			 END IF;
			END PROCESS;
		
		
		
  END behav;      
            
```
