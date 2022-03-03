import hashlib
from itsdangerous import URLSafeTimedSerializer
from flask.sessions import TaggedJSONSerializer

salt = 'cookie-session'
serializer = TaggedJSONSerializer()
signer_kwargs = {
    'key_derivation': 'hmac',
    'digest_method': hashlib.sha1
}

# you can set secret key using "app.secret_key="yoursecretkey"" in your main file
s = URLSafeTimedSerializer('your secret key', salt=salt, serializer=serializer, signer_kwargs=signer_kwargs)
# cookie code after "session="
print(s.loads('your cookie to decode'))
