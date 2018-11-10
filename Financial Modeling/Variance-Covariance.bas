
Function constantcorr(data As Range, corr As Double) _    
As Variant 
    Dim i As Integer        
    Dim j As Integer        
    Dim numcols As Integer        
    numcols  =  data.Columns.Count        
    numrows  =  data.Rows.Count        
    Dim matrix() As Double        
    ReDim matrix(numcols - 1, numcols - 1)        
    If Abs(corr)  >  =  1 Then GoTo Out        
    For i  =  1 To numcols        
    For j  =  1 To numcols   
        If i  =  j Then            
        matrix(i - 1, j - 1)  =  Application. _           
        WorksheetFunction.Var_S(data.Columns(i))           
        Else 
        matrix(i - 1, j - 1)  =  corr * jjunk(data, i) * _ 
        jjunk(data, j) 
       End If
     Next j 
     Next i 
 Out:
    If Abs(corr)  >  =  1 Then constantcorr  =  VarCovar(data) _ 
    Else constantcorr  =  matrix 
End Function





