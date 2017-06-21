
require 'net/http'
require 'uri'

class Submitter

  MAP_EXTNAME_LANGUAGE = {
    '.c'    => :c,
    '.cpp'  => :cpp,
    '.cc'   => :cpp,
    '.C'    => :cpp,
    '.java' => :java,
  }

  JUDGE_SETTING = {
    
    :aoj => {
      :name => "Aizu Online Judge",
      
      :uri  => 'rose.u-aizu.ac.jp',
      :path => '/onlinejudge/servlet/Submit',
     
      :map_form_name => {
        :username  => 'userID',
        :password  => 'password',
        :problemID => 'problemNO',
        :language  => 'language',
        :program   => 'sourceCode'
      },

      :map_form_value_language => {
        :c    => 'C',
        :cpp  => 'C++',
        :java => 'JAVA',
      }
    }
  }
  

  USER_SETTING = {
    :aoj => {
      :username => 'db2',
      :password => '0710',
    },
  }

  def main()
    set_params()
    submit()
  end
  
  def set_params()
    @filename  = nil
    @judge     = nil

    while(!ARGV.empty? && ARGV.first[0..0] == '-')
      option   = ARGV[0].dup
      argument = ARGV[1].dup
      ARGV.shift()
      ARGV.shift()

      if(!(option && argument))
        raise "Invalid option specified."
      end

      case(option)
      when '-judge', '-j'
        @judge     = argument.downcase.intern
      when '-problemID', '-p'
        @problemID = argument
      when '-language', '-lang', '-l'
        @language  = argument.downcase.intern
      else
        raise "Option '#{option}' is not defined."
      end
    end

    raise "Judge is not specified."     unless @judge
    raise "Filename is not specified."  unless ARGV[0]
    
    @filename = ARGV[0]
    @language  = get_language(@filename)  unless @language
    @problemID = get_problemID(@filename) unless @problemID
  end

  def get_language(filename)
    return MAP_EXTNAME_LANGUAGE[File.extname(filename)]
  end

  def get_problemID(filename)
    return File.basename(filename).split(/[^0-9]/).first
  end

  def submit()
    judge = JUDGE_SETTING[@judge]
    uri   = judge[:uri]
    path  = judge[:path]
    data  = create_data()

    print_log()

    # --------

    Net::HTTP.start(uri) { |http|
      response = http.post(path, data)
      print response.code, ' ', response.message, "\n"
    }
  end

  def print_log()
    STDERR << "Submitting...\n"

    STDERR << "Judge:    " << JUDGE_SETTING[@judge][:name] << "\n"
    STDERR << "Problem:  " << @problemID << "\n"
    STDERR << "Language: " << @language.to_s.capitalize << "\n"
    STDERR << "Filename: " << @filename << "\n"    
  end

  def create_data()    
    judge = JUDGE_SETTING[@judge]
    user  = USER_SETTING[@judge]
    
    params = {
      :username => user[:username],
      :password => user[:password],
      
      :problemID => @problemID,
      :language  => judge[:map_form_value_language][@language],
      :program   => File.open(@filename).read(),
    }

    form_name = judge[:map_form_name]

    return params.map{ |key, value|
      enc(form_name[key]) + '=' + enc(value)
    }.join('&')
  end

  def enc(str)
    return URI.encode(str, /./n)
  end
end

Submitter.new.main()
