' VBA For Quantitative Finance                                
' TwoStageGordon
' Author: David Li  

Function TwoStageGordon(P0, Div0, Highgrowth, _    
Highgrowthyrs, Normalgrowth)        
    high  =  1        
    low  =  0                
    Do While (high - low)  >  0.00001        
    Estimate  =  (high  +  low) / 2        
    factor  =  (1  +  Highgrowth) / _        
    (1  +  Estimate)        
    Term1  =  Div0 * factor * (1 - factor  ∧  _        
    Highgrowthyrs) / (1 - factor)        
    Term2  =  Div0 * factor  ∧  Highgrowthyrs * _        
    (1  +  Normalgrowth) / (Estimate - _        
    Normalgrowth)        
    If (Term1  +  Term2)  >  P0 Then            
          low  =  (high  +  low) / 2            
          Else:  high  =  (high  +  low) / 2        
    End If        
    Loop        
    TwoStageGordon  =  (high  +  low) / 2    
End Function
