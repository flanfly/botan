/*************************************************
* Configuration Handling Header File             *
* (C) 1999-2006 The Botan Project                *
*************************************************/

#ifndef BOTAN_POLICY_CONF_H__
#define BOTAN_POLICY_CONF_H__

#include <botan/types.h>
#include <botan/enums.h>
#include <string>
#include <vector>
#include <map>

namespace Botan {

/*************************************************
* Library Configuration Settings                 *
*************************************************/
class Config
   {
   public:
      std::string get(const std::string&, const std::string&) const;
      bool is_set(const std::string&, const std::string&) const;
      void set(const std::string&, const std::string&,
               const std::string&, bool = true);

      u32bit option_as_u32bit(const std::string&) const;
      u32bit option_as_time(const std::string&) const;
      bool option_as_bool(const std::string&) const;
      std::vector<std::string> option_as_list(const std::string&) const;

      std::string deref_alias(const std::string&) const;
      std::string option(const std::string&) const;

      void load_inifile(const std::string&);
   private:
      std::map<std::string, std::string> settings;
   };

/*************************************************
* Hook for the global config                     *
*************************************************/
Config& global_config();

namespace ConfigXXX {

/*************************************************
* Choose the signature format for a PK algorithm *
*************************************************/
void choose_sig_format(const std::string&, std::string&, Signature_Format&);
void choose_sig_format(const std::string&, std::string&, std::string&,
                       Signature_Format&);

}

}

#endif
