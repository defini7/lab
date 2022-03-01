import requests
from time import sleep

def do_dollar(from_currency, to_currency, api_key):
  url= "https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE" + "&from_currency=" + from_currency + "&to_currency=" + to_currency + "&apikey=" + api_key

  while True:
    req = requests.get(url)

    result = req.json()

    buy = result['Realtime Currency Exchange Rate']['5. Exchange Rate']
    time = result['Realtime Currency Exchange Rate']['6. Last Refreshed']
    print(f'{time}. 1 USD - %0.4f RUB' % float(buy))

    sleep(15)

do_dollar('USD', 'RUB', '### YOUR API GOES HERE ###')
