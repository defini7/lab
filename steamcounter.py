# not really smart

from requests import get
from datetime import datetime

webapi = input('Your Web API: ')
steamid = input('Your Steam64 ID: ')


def compute_cost():
    total = 0.0

    url = f'http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key={webapi}&steamid={steamid}&format=json'

    all_games = get(url).json()['response']['games']

    for game in all_games:
        game_id = str(game['appid'])
        price_request = 'https://store.steampowered.com/api/appdetails?appids=' + game_id
        try:
            total += int(get(price_request).json()[game_id]['data']['price_overview']['final']) / 100
        except Exception:
            pass

    return total


t = datetime.now()
print('Total:', compute_cost())
print('Took', datetime.now() - t, 'to compute.')
