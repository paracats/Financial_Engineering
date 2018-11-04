
Function getformula(r As Range) As String
    Application.Volatile
    If r.HasArray Then
    getformula = " < -- " & _
      " {" & r.FormulaArray & "}"
    Else
    getformula = " < -- " & _
     " " & r.FormulaArray
     End If
End Function

