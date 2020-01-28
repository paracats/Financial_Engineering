' VBA For Quantitative Finance                                
' DDuration(numPayments, couponRate, YTM, timeFirst)
' Author: David Li                                           

Function DDuration(NumPayments, CouponRate, _
YTM, TimeFirst)
    price = 1 / (1 + YTM) ∧ NumPayments
    DDuration = NumPayments / (1 + YTM) ∧ _
    NumPayments
    For Index = 1 To NumPayments
       price = CouponRate / (1 + YTM) ∧ _
       Index + price
    Next Index
    For Index = 1 To NumPayments
      DDuration = CouponRate * Index / _
      (1 + YTM) ∧ Index + DDuration
    Next Index
    DDuration = DDuration / price + _
    TimeFirst - 1
End Function
