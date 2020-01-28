' VBA For Quantitative Finance                                
' Co-variance
' Author: David Li   

Function VarCovar(rng As Range) As Variant 
    Dim i As Integer       
    Dim j As Integer   
    Dim numcols As Integer 
    numcols  =  rng.Columns.Count 
    numrows  =  rng.Rows.Count     
    Dim matrix() As Double     
    ReDim matrix(numcols - 1, numcols - 1) 
    For i  =  1 To numcols      
      For j  =  1 To numcols    
         matrix(i - 1, j - 1)  =  _    
       Application.WorksheetFunction.  
  Covariance_S(rng.Columns(i), _       
      rng.Columns(j))  
      Next j       
    Next i       
    VarCovar  =  matrix    
  End Function  
