' VBA For Quantitative Finance                                
' YTM for Uneven Payments 
' Author: Shaofei Li                                           

Function Annuityvalue(interest, numPeriods)
   annuityvalue = 0
   For Index = 1 To numPeriods
      annuityvalue = annuityvalue + 1 / _
      (1 + interest) ∧ Index
   Next Index
End Function

Function UnevenYTM(CouponRate, FaceValue, _
BondPrice, NumPayments, TimeFirst, epsilon)
   Dim YTM As Double
   high = 1
   low = 0
      While Abs(annuityvalue(YTM, _
      NumPayments) * CouponRate * _
         FaceValue + FaceValue / _
         (1 + YTM) ∧ NumPayments - _
         BondPrice / (1 + YTM) ∧ _
         (1 - TimeFirst)) >= epsilon
      YTM = (high + low) / 2
      If annuityvalue(YTM, NumPayments) * _
      CouponRate * _
          FaceValue + FaceValue / (1 + YTM) _
          ∧ NumPayments - BondPrice / _
          (1 + YTM) ∧ (1 - TimeFirst) > 0 _
          Then
             low = YTM
          Else
             high = YTM
      End If
      Wend
  UnevenYTM = (high + low) / 2
End Function
