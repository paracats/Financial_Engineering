
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
        F





