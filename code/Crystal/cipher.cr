module CaesarCipher
  def self.encrypt(string : String)
    string.chars.map{ |char| ((char.upcase.ord - 52) % 26 + 65).chr }.join
  end
end

def CaesarCipher.decrypt(string : String)
  encrypt(string)
end

cipher = CaesarCipher.encrypt("HELLO") # => "URYYB"
cipher = CaesarCipher.encrypt("HELLO") # => "URYYB"

puts cipher
puts CaesarCipher.decrypt(cipher) # => "HELLO"
