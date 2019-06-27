namespace database_course_design
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("userdata")]
    public partial class userdata
    {
        [Required]
        [StringLength(20)]
        public string username { get; set; }

        [Required]
        [StringLength(20)]
        public string passwd { get; set; }

        [Key]
        [StringLength(5)]
        public string worknum { get; set; }

        public short? authority { get; set; }
    }
}
