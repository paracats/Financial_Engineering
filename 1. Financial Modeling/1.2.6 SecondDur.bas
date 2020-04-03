' VBA For Quantitative Finance                                
' secondDur(numberPayments, couponRate, YTM)
' Author: Shaofei Li                                           

Function secondDur(numberPayments, couponRate,
YTM)

   For Index = 1 To numberPayments
       If Index < numberPayments Then
          secondDur = couponRate * Index * _
          (Index + 1) / (1 + YTM) ∧ Index + _
               secondDur
       Else
          secondDur = (couponRate + 1) * _
          Index * (Index + 1) _
              / (1 + YTM) ∧ Index + _
              secondDur
       End If

       secondDur = secondDur
  Next Index
  
End Function
