
 Function ImpliedVolVarCov(varcovarmatrix As _ 
  Range, volatilities As Range, corr As Double) 
  As Variant       
  Dim i As Integer       
  Dim j As Integer       
  Dim numcols As Integer  
  numcols  =  varcovarmatrix.Columns.Count       
  numrows  =  numcols       
  Dim matrix() As Double       
  ReDim matrix(numcols - 1, numcols - 1)       If Abs(corr)  >  =  1 Then GoTo Out 
