' VBA For Quantitative Finance                                
' SIM
' Author: David Li  

Function sim(assetdata As Range, marketdata As Range) _ 
As Variant 
    Dim i As Integer        
    Dim j As Integer        
    Dim numcols As Integer        
    numcols  =  assetdata.Columns.Count        
    Dim matrix() As Double        
    ReDim matrix(numcols - 1, numcols - 1) 

    For i  =  1 To numcols        
    For j  =  1 To numcols
    
        If i  =  j Then            
        matrix(i - 1, j - 1)  =  Application. _            
        WorksheetFunction.Var_S(assetdata.Columns(i))            
        Else            
        matrix(i - 1, j - 1)  =  _ 
      Application.WorksheetFunction.Slope(assetdata. _          
      Columns(i), marketdata) * _          
      Application.WorksheetFunction.Slope(assetdata. _          
      Columns(j), marketdata) * _          
      Application.WorksheetFunction.Var_S(marketdata)   
   End If        
   Next j        
   Next i        
   sim  =  matrix 
End Function  
