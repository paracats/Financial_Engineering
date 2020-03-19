' VBA For Quantitative Finance                                
' BLtracking
' Author: Shaofei Li   

 Function BLtracking(rng As Range) As Variant   
   Dim i As Integer       
   Dim j As Integer       
   Dim numcols As Integer       
   numcols  =  rng.Columns.Count       
   Dim matrix() As Double       
   ReDim matrix(numcols - 1, numcols - 1)       
   For i  =  1 To numcols       
     For j  =  1 To numcols   
       matrix(i - 1, j - 1)  =  rng(i, j) _ 
         / rng(i, i)  
   Next j       
   Next i       
   BLtracking  =  matrix 
End Function 
