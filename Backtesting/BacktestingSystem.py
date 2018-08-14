""" BacktestingSystem         """
""" David Li                  """

from BacktesterClass import Backtester

backtester = Backtester("AAPL",dt.datetime(2014, 1, 1),
                               dt.datetime(2014, 12, 31))

backtester.start_backtest()                              
