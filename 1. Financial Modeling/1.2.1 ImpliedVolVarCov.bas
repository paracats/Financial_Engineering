' VBA For Quantitative Finance                                
' ImpliedVolVarCov
' Author: Shaofei Li  

 Function ImpliedVolVarCov(varcovarmatrix As _ 
  Range, volatilities As Range, corr As Double) 
  As Variant       
  Dim i As Integer       
  Dim j As Integer       
  Dim numcols As Integer  
  numcols  =  varcovarmatrix.Columns.Count       
  numrows  =  numcols       
  Dim matrix() As Double       
  ReDim matrix(numcols - 1, numcols - 1)       
  If Abs(corr)  >  =  1 Then GoTo Out 
  For i  =  1 To numcols        
  For j  =  1 To numcols       
   If i  =  j Then       
   matrix(i - 1, j - 1)  =  volatilities(i)  ∧  2       
   Else       
   matrix(i - 1, j - 1)  =  corr * _ 
     volatilities(i) * volatilities(j)       
   End If       
 Next j        
 Next i    
Out:       
 If Abs(corr)  >  =  1 Then ImpliedVolVarCov  =  _ 
   “ERR” Else ImpliedVolVarCov  =  matrix    
End Function 
