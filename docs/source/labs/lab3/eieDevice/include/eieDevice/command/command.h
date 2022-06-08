#ifndef COMMAND_H_
#define COMMAND_H_

/** General information related to a command */
struct CommandInfo {
   const char *name;
   void *priv;
   void (*command_fn)(const char *name, void *priv, const char *req_msg, char *resp_msg,);
};

/** Command operations to implement specific commands */
struct CommandOps {
    /** execute a command */
    const char (*execute)(struct CommandInfo *info, void name, void *priv);
};

/** Command structure */
struct Command {
    /** Command information */
    struct CommandInfo info;
    /** Command operations */
    struct CommandOps *ops;
    /** Command private data passed to ops */
    void *priv;
};

/**
 * Creates a command
 *
 *
 * @param info Command information structure.
 * @param ops  Command operations.
 * @param priv Command private data.
 *
 * @return Pointer to a sensor manager structure.
 */
struct Command *command_create(struct CommandInfo *info,
                             struct CommandOps *ops,
                             void *priv);

/**
 * Execute command
 *
 * @param cmd Command structure.
 *
 * @return response.
 */
void command_execute(struct Command *cmd);

/**
 * Destroys the command
 *
 * @param cmd Command structure.
 */
void command_destroy(struct Command *cmd);

#endif // COMMAND_H_
