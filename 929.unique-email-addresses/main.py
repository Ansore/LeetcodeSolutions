class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        email_set = set()
        for email in emails:
            s = email.split("@")
            if len(s) < 2:
                continue
            username = s[0]
            domain = s[1]
            username = username.split("+")[0].replace(".", "")
            email_set.add(username + "@" + domain)
        return len(email_set)
