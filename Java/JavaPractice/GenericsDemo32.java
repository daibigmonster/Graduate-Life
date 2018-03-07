interface info{
}

class Contact implements info{
    private String address;
    private String telephone;
    private String zipcode;
    public Contact(String addString,String telephone,String zipcode)
    {
        this.setAddress(address);
        this.setTelephone(telephone);
        this.setZipcode(zipcode);
    }
    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    public String getTelephone() {
        return telephone;
    }
    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }
    public String getZipcode() {
        return zipcode;
    }
    public void setZipcode(String zipcode) {
        this.zipcode = zipcode;
    }
    public String toString()
    {
        return "联系方式: " + "\n" + 
        "\t |- 联系电话: " + this.telephone + "\n" +
        "\t |- 联系地址: " + this.address + "\n" +
        "\t |- 邮政编码: " + this.zipcode + "\n";
    }
}